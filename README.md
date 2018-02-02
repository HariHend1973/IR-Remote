IR REMOTE DI PULPSTONE/LEDE

untuk yg pingin coba remote control di pulsote/lede tapi belum bisa compile lirc package, ada alternative lain(selain triggrehappy).

required
- ash/sh
- IR receiver/remote ( bentuknya daa di video yg di post)
- arduino uno/nano/pro micro (kemampuan mengcompile dan mengupload ke arduino melalui arduino IDE)
- kabel usb jumper type A (router) ke type B (arduino)

steps arduino
- sambungkan jumper dari arduino ke IR receiver(sesuaikan pin assignment, lihat datasheet IR)
ARDUINO-----IR
VCC---------VCC
GND---------GND
D3----------DATA
- download source code arduino + IR receiver
https://drive.google.com/file/d/1dGKk8KpWdx5MVf-Wyn49lWTAAaDbAm2y/view?usp=drivesdk
atau disini:
https://github.com/HariHend1973/IR-Remote.git
- ekstrak
- download IRRemote library untuk arduino
menu: sketch->include library->manage library, library manager, search IRRemote by Shirriff
- open sourcecode yg telah di extrak sebelumnya, compile dan upload ke arduino.
- test melalui serial monitor di IDE, akan keluar karakter hexadecimal
- done

steps di pulstone/lede
- download skrip remote.sh
https://drive.google.com/file/d/1Dvse_bnUfgdRuDid_h9ujKWG5Hya42f-/view?usp=drivesdk
upload ke router(ke directory apa saja)
- opkg update && opkg install kmod-usb-acm coreutils-stty kmod-usb-serial-ch341
- konek usb jumper dari usb port arduino ke usb port router
- execute skrip dengan cara sh remote.sh
- atau masukan di rc.local supaya otomatis jalan sewktu boot
sh /root/mpdlcd/remote.sh > /dev/null 2>&1 &
- test, kalo sudah berhasil silakan pencet2 remote sepanjang hari :D
