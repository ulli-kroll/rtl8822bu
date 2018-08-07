rtl8812bu for linux
===================

rtl8812bu linux kernel driver Wireless Dual-Band USB Adapter

For the USB3 issue read at the end  

<u>If one USB-ID is missing, please mail me.</u>  

build/load/function tested with v4.17.12  


Building and install driver
---------------------------

for building type  
`make`  

for load the driver  
`sudo modprobe cfg80211`  
`sudo insmod rtl8812bu.ko`  


You need to install the needed fw with  
`sudo make installfw`  

If you need to crosscompile use  
`ARCH= CROSS_COMPILE= KSRC=`  
while calling `make` i.e.  

`make ARCH="arm" CROSS_COMPILE=armv5tel-softfloat-linux-gnueabi- KSRC=/home/linux-master modules`  

USB3 Mode Issue
---------------
Realtek aka the chipdesigner does some **stupid** idea to switch into USB3 mode via special efuse read/write.  
Will check for this and enable USB3

Please use prefix  
rtl8812bu:  
in subject line  
TIA  

Hans Ulli Kroll <ulli.kroll@googlemail.com>
