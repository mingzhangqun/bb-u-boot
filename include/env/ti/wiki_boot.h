#ifndef __WIKI_BOOT_H__
#define __WIKI_BOOT_H__

#define EEPROM_PROGRAMMING \
	"eeprom_dump=i2c dev 0; " \
		"i2c md 0x50 0x00.2 20; " \
		"\0" \
	"eeprom_blank=i2c dev 0; " \
		"i2c mw 0x50 0x00.2 ff; " \
		"i2c mw 0x50 0x01.2 ff; " \
		"i2c mw 0x50 0x02.2 ff; " \
		"i2c mw 0x50 0x03.2 ff; " \
		"i2c mw 0x50 0x04.2 ff; " \
		"i2c mw 0x50 0x05.2 ff; " \
		"i2c mw 0x50 0x06.2 ff; " \
		"i2c mw 0x50 0x07.2 ff; " \
		"i2c mw 0x50 0x08.2 ff; " \
		"i2c mw 0x50 0x09.2 ff; " \
		"i2c mw 0x50 0x0a.2 ff; " \
		"i2c mw 0x50 0x0b.2 ff; " \
		"i2c mw 0x50 0x0c.2 ff; " \
		"i2c mw 0x50 0x0d.2 ff; " \
		"i2c mw 0x50 0x0e.2 ff; " \
		"i2c mw 0x50 0x0f.2 ff; " \
		"i2c mw 0x50 0x10.2 ff; " \
		"i2c mw 0x50 0x11.2 ff; " \
		"i2c mw 0x50 0x12.2 ff; " \
		"i2c mw 0x50 0x13.2 ff; " \
		"i2c mw 0x50 0x14.2 ff; " \
		"i2c mw 0x50 0x15.2 ff; " \
		"i2c mw 0x50 0x16.2 ff; " \
		"i2c mw 0x50 0x17.2 ff; " \
		"i2c mw 0x50 0x18.2 ff; " \
		"i2c mw 0x50 0x19.2 ff; " \
		"i2c mw 0x50 0x1a.2 ff; " \
		"i2c mw 0x50 0x1b.2 ff; " \
		"i2c mw 0x50 0x1c.2 ff; " \
		"i2c mw 0x50 0x1d.2 ff; " \
		"i2c mw 0x50 0x1e.2 ff; " \
		"i2c mw 0x50 0x1f.2 ff; " \
		"\0" \
	"eeprom_bbb_header=i2c dev 0; " \
		"i2c mw 0x50 0x00.2 aa; " \
		"i2c mw 0x50 0x01.2 55; " \
		"i2c mw 0x50 0x02.2 33; " \
		"i2c mw 0x50 0x03.2 ee; " \
		"i2c mw 0x50 0x04.2 41; " \
		"i2c mw 0x50 0x05.2 33; " \
		"i2c mw 0x50 0x06.2 33; " \
		"i2c mw 0x50 0x07.2 35; " \
		"i2c mw 0x50 0x08.2 42; " \
		"i2c mw 0x50 0x09.2 4e; " \
		"i2c mw 0x50 0x0a.2 4c; " \
		"i2c mw 0x50 0x0b.2 54; " \
		"\0" \
	"eeprom_bbbl_footer= " \
		"i2c mw 0x50 0x0c.2 42; " \
		"i2c mw 0x50 0x0d.2 4c; " \
		"i2c mw 0x50 0x0e.2 41; " \
		"i2c mw 0x50 0x0f.2 32; " \
		"\0" \
	"eeprom_bbbw_footer= " \
		"i2c mw 0x50 0x0c.2 42; " \
		"i2c mw 0x50 0x0d.2 57; " \
		"i2c mw 0x50 0x0e.2 41; " \
		"i2c mw 0x50 0x0f.2 35; " \
		"\0" \
	"eeprom_bbgg_footer= " \
		"i2c mw 0x50 0x0c.2 47; " \
		"i2c mw 0x50 0x0d.2 47; " \
		"i2c mw 0x50 0x0e.2 31; " \
		"i2c mw 0x50 0x0f.2 41; " \
		"\0" \
	"eeprom_pocketbeagle= " \
		"i2c mw 0x50 0x00.2 aa; " \
		"i2c mw 0x50 0x01.2 55; " \
		"i2c mw 0x50 0x02.2 33; " \
		"i2c mw 0x50 0x03.2 ee; " \
		"i2c mw 0x50 0x04.2 41; " \
		"i2c mw 0x50 0x05.2 33; " \
		"i2c mw 0x50 0x06.2 33; " \
		"i2c mw 0x50 0x07.2 35; " \
		"i2c mw 0x50 0x08.2 50; " \
		"i2c mw 0x50 0x09.2 42; " \
		"i2c mw 0x50 0x0a.2 47; " \
		"i2c mw 0x50 0x0b.2 4c; " \
		"i2c mw 0x50 0x0c.2 30; " \
		"i2c mw 0x50 0x0d.2 30; " \
		"i2c mw 0x50 0x0e.2 41; " \
		"i2c mw 0x50 0x0f.2 32; " \
		"\0" \

#define EEWIKI_BOOT \
	"boot=${devtype} dev ${mmcdev}; " \
		"if ${devtype} rescan; then " \
			"setenv bootpart ${mmcdev}:1; " \
			"if test -e ${devtype} ${bootpart} /etc/fstab; then " \
				"setenv mmcpart 1;" \
			"fi; " \
			"echo Checking for: /uEnv.txt ...;" \
			"if test -e ${devtype} ${bootpart} /uEnv.txt; then " \
				"if run loadbootenv; then " \
					"echo Loaded environment from /uEnv.txt;" \
					"run importbootenv;" \
				"fi;" \
				"echo Checking if uenvcmd is set ...;" \
				"if test -n ${uenvcmd}; then " \
					"echo Running uenvcmd ...;" \
					"run uenvcmd;" \
				"fi;" \
			"fi; " \
			"echo Checking for: /boot/uEnv.txt ...;" \
			"for i in 1 2 3 4 5 6 7 ; do " \
				"setenv mmcpart ${i};" \
				"setenv bootpart ${mmcdev}:${mmcpart};" \
				"if test -e ${devtype} ${bootpart} /boot/uEnv.txt; then " \
					"load ${devtype} ${bootpart} ${loadaddr} /boot/uEnv.txt;" \
					"env import -t ${loadaddr} ${filesize};" \
					"echo Loaded environment from /boot/uEnv.txt;" \
					"if test -n ${dtb}; then " \
						"echo debug: [dtb=${dtb}] ... ;" \
						"setenv fdtfile ${dtb};" \
						"echo Using: dtb=${fdtfile} ...;" \
					"fi;" \
					"echo Checking if uname_r is set in /boot/uEnv.txt...;" \
					"if test -n ${uname_r}; then " \
						"setenv oldroot /dev/mmcblk${mmcdev}p${mmcpart};" \
						"echo Running uname_boot ...;" \
						"run uname_boot;" \
					"fi;" \
				"fi;" \
			"done;" \
		"fi;\0" \

#define EEWIKI_UNAME_BOOT \
	"uname_boot="\
		"setenv bootdir /boot; " \
		"setenv bootfile vmlinuz-${uname_r}; " \
		"if test -e ${devtype} ${bootpart} ${bootdir}/${bootfile}; then " \
			"echo loading ${bootdir}/${bootfile} ...; "\
			"run loadimage;" \
			"setenv fdtdir /boot/dtbs/${uname_r}; " \
			"if test -e ${devtype} ${bootpart} ${fdtdir}/${fdtfile}; then " \
				"run loadfdt;" \
			"else " \
				"setenv fdtdir /usr/lib/linux-image-${uname_r}; " \
				"if test -e ${devtype} ${bootpart} ${fdtdir}/${fdtfile}; then " \
					"run loadfdt;" \
				"else " \
					"setenv fdtdir /lib/firmware/${uname_r}/device-tree; " \
					"if test -e ${devtype} ${bootpart} ${fdtdir}/${fdtfile}; then " \
						"run loadfdt;" \
					"else " \
						"setenv fdtdir /boot/dtb-${uname_r}; " \
						"if test -e ${devtype} ${bootpart} ${fdtdir}/${fdtfile}; then " \
							"run loadfdt;" \
						"else " \
							"setenv fdtdir /boot/dtbs; " \
							"if test -e ${devtype} ${bootpart} ${fdtdir}/${fdtfile}; then " \
								"run loadfdt;" \
							"else " \
								"setenv fdtdir /boot/dtb; " \
								"if test -e ${devtype} ${bootpart} ${fdtdir}/${fdtfile}; then " \
									"run loadfdt;" \
								"else " \
									"setenv fdtdir /boot; " \
									"if test -e ${devtype} ${bootpart} ${fdtdir}/${fdtfile}; then " \
										"run loadfdt;" \
									"else " \
										"if test -e ${devtype} ${bootpart} ${fdtfile}; then " \
											"run loadfdt;" \
										"else " \
											"echo; echo unable to find [dtb=${fdtfile}] did you name it correctly? ...; " \
											"run failumsboot;" \
										"fi;" \
									"fi;" \
								"fi;" \
							"fi;" \
						"fi;" \
					"fi;" \
				"fi;" \
			"fi; " \
			"setenv rdfile initrd.img-${uname_r}; " \
			"if test -e ${devtype} ${bootpart} ${bootdir}/${rdfile}; then " \
				"echo loading ${bootdir}/${rdfile} ...; "\
				"run loadrd;" \
				"if test -n ${netinstall_enable}; then " \
					"run args_netinstall; run message;" \
					"echo debug: [${bootargs}] ... ;" \
					"echo debug: [bootz ${loadaddr} ${rdaddr}:${rdsize} ${fdtaddr}] ... ;" \
					"bootz ${loadaddr} ${rdaddr}:${rdsize} ${fdtaddr}; " \
				"fi;" \
				"if test -n ${uenv_root}; then " \
					"run args_uenv_root;" \
					"echo debug: [${bootargs}] ... ;" \
					"echo debug: [bootz ${loadaddr} ${rdaddr}:${rdsize} ${fdtaddr}] ... ;" \
					"bootz ${loadaddr} ${rdaddr}:${rdsize} ${fdtaddr}; " \
				"fi;" \
				"if test -n ${uuid}; then " \
					"run args_mmc_uuid;" \
					"echo debug: [${bootargs}] ... ;" \
					"echo debug: [bootz ${loadaddr} ${rdaddr}:${rdsize} ${fdtaddr}] ... ;" \
					"bootz ${loadaddr} ${rdaddr}:${rdsize} ${fdtaddr}; " \
				"fi;" \
				"run args_mmc_old;" \
				"echo debug: [${bootargs}] ... ;" \
				"echo debug: [bootz ${loadaddr} ${rdaddr}:${rdsize} ${fdtaddr}] ... ;" \
				"bootz ${loadaddr} ${rdaddr}:${rdsize} ${fdtaddr}; " \
			"else " \
				"if test -n ${uenv_root}; then " \
					"run args_uenv_root;" \
					"echo debug: [${bootargs}] ... ;" \
					"echo debug: [bootz ${loadaddr} - ${fdtaddr}] ... ;" \
					"bootz ${loadaddr} - ${fdtaddr}; " \
				"fi;" \
				"run args_mmc_old;" \
				"echo debug: [${bootargs}] ... ;" \
				"echo debug: [bootz ${loadaddr} - ${fdtaddr}] ... ;" \
				"bootz ${loadaddr} - ${fdtaddr}; " \
			"fi;" \
		"fi;\0" \

#endif // __WIKI_BOOT_H__
