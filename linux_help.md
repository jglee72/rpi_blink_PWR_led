# Linux Commands
____
### Search for available wifi network
    sudo iwlist wlan0 scan

### Network info
    route -n
    
### More IP Stuff
    ip route

### Process list
    ps -ef

### List files (full detail); most recent last 
    ls -ltr

### Check available memory
    free -m

### Process cpu and memory. SHIFT-F for  options.
    top

### Password changes
    - sudo passwd   #change root password
    - passwd        #change password of current user
    - passwd nnnnn  #change and or create user nnnnnn password

### Output ASCII file to terminal
    less <filename>

### Update OS
    sudo apt-get update
    sudo apt-get dist-upgrade
    
### Samba Server to share files

```
install samba
sudo apt-get update
sudo apt-get dist-upgrade
sudo apt-get install samba samba-common-bin
sudo mkdir -m 1777 /home/pi/PiShare
```
in the following file
```
sudo nano /etc/samba/smb.conf
```
Edit the following
```
workgroups = WORKGROUPS
wins support = yes
```
And add the following to end of file 
```
[Pishare]
Comment = Pi shared folder
Path = /home/pi/PiShare
Browseable = yes
Writeable = Yes
only guest = no
create mask = 0777
directory mask = 0777
Public = no
Guest ok = yes
```

Set a password for samba server for user "pi"
    sudo smbpasswd -a pi
follow prompts to enter new password twice

Start Samba Server
    sudo /etc/init.d/samba restart

From now on, Samba will start automatically whenever you power on your Pi
To see your server go to any windows File Explorer using 
\\192.168.0.105\PiShare


### Ethernet files

General Ethernet configuration
    /etc/network/interfaces
Supposedly where Static IP info located
    /etc/dhcpcd.conf
Network Password location
    /etc/wpa_supplicant/wpa_supplicant.conf

