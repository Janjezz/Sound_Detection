# Sound_Detection

sve e realizuje preko blink timer callback – U TOJ FJI JE CELA SUSTINA
sve se desava u 25 ms
kod pocinje od gpio_init - a
u gpio_driver exitu rdimo  dealociranje , ciscenje drivera

 Prvi terminal:
1 cd Desktop/DetekcijaZvuka/detekcijaZvuka/
2  make
3 insmod gpio_driver.ko  	// insmod ucitava driver u kernel module
4 sudo rmmod gpio_driver.ko   		//da uradimo unmake od fajla
dmesg –k  - kuca se u terminalu za rukovalac
Drugi termnal:
1 cd Desktop/DetekcijaZvuka/detekcijaZvukaTestApp/
2 make
3  cd bin/Realese/
4 sudo mknod  soundDetection c 242 0
5 sudo ./gpio_driver_test_app

sudo cat/proc/kmsg    - real time detekcija zvuka


sprega sa korisnickim prostorom je aplikacija
