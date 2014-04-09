# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|
  config.vm.define :host do |host_config|
    host_config.vm.box = "debiansqueeze32"
    host_config.vm.box_url = "http://files.vagrantup.com/lucid32.box"

    host_config.vm.hostname = "hacky"
    host_config.vm.network :private_network, ip: "192.168.176.10"

    host_config.ssh.forward_x11 = true

    host_config.vm.provider :virtualbox do |vb|
      # Don't boot with headless mode
      vb.gui = false

      # Use VBoxManage to customize the VM. For example to change memory
      vb.customize ["modifyvm", :id, "--memory", "1024", "--cpus", "1"]

      #Fix Symlinks in Virtualbox Shared Folders
      vb.customize ["setextradata", :id, "VBoxInternal2/SharedFoldersEnableSymlinksCreate/v-root", "1"]

    end
    host_config.vm.provision :shell, :path => 'setup.sh'
  end

end
