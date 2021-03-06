/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 1000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 2048

/*
 * function            description                     argument (example)
 *
 * battery_perc        battery percentage              battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_state       battery charging state          battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_remaining   battery remaining HH:MM         battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * cpu_perc            cpu usage in percent            NULL
 * cpu_freq            cpu frequency in MHz            NULL
 * datetime            date and time                   format string (%F %T)
 * disk_free           free disk space in GB           mountpoint path (/)
 * disk_perc           disk usage in percent           mountpoint path (/)
 * disk_total          total disk space in GB          mountpoint path (/")
 * disk_used           used disk space in GB           mountpoint path (/)
 * entropy             available entropy               NULL
 * gid                 GID of current user             NULL
 * hostname            hostname                        NULL
 * ipv4                IPv4 address                    interface name (eth0)
 * ipv6                IPv6 address                    interface name (eth0)
 * kernel_release      `uname -r`                      NULL
 * keyboard_indicators caps/num lock indicators        format string (c?n?)
 *                                                     see keyboard_indicators.c
 * keymap              layout (variant) of current     NULL
 *                     keymap
 * load_avg            load average                    NULL
 * netspeed_rx         receive network speed           interface name (wlan0)
 * netspeed_tx         transfer network speed          interface name (wlan0)
 * num_files           number of files in a directory  path
 *                                                     (/home/foo/Inbox/cur)
 * ram_free            free memory in GB               NULL
 * ram_perc            memory usage in percent         NULL
 * ram_total           total memory size in GB         NULL
 * ram_used            used memory in GB               NULL
 * run_command         custom shell command            command (echo foo)
 * separator           string to echo                  NULL
 * swap_free           free swap in GB                 NULL
 * swap_perc           swap usage in percent           NULL
 * swap_total          total swap size in GB           NULL
 * swap_used           used swap in GB                 NULL
 * temp                temperature in degree celsius   sensor file
 *                                                     (/sys/class/thermal/...)
 *                                                     NULL on OpenBSD
 *                                                     thermal zone on FreeBSD
 *                                                     (tz0, tz1, etc.)
 * uid                 UID of current user             NULL
 * uptime              system uptime                   NULL
 * username            username of current user        NULL
 * vol_perc            OSS/ALSA volume in percent      mixer file (/dev/mixer)
 *                                                     NULL on OpenBSD
 * wifi_perc           WiFi signal in percent          interface name (wlan0)
 * wifi_essid          WiFi ESSID                      interface name (wlan0)
 */

static const struct arg args[] = {
	/* function format          argument */
    { netspeed_rx,   "^b#2a2a31^^c#ffffff^ RX %sB/s ", "wlp82s0"             },
    { run_command,   "^b#2e2e33^^c#ffffff^ IP %2s ", "curl -s ifconfig.io"         },
    { run_command,   "^b#39393d^^c#ffffff^ ADA %2s ", "curl -s rate.sx/ada | awk '/begin:/ {print $8}'"         },
    { run_command,   "^b#444448^^c#ffffff^ BTC %2s ", "curl -s rate.sx/btc | awk '/begin:/ {print $8}'"         },
	{ cpu_perc,      "^b#4f4f53^^c#ffffff^ CPU %2s%% ",  NULL   			 },
	{ ram_perc,      "^b#5a5a5e^^c#ffffff^ RAM %2s%% ",  NULL   			 },
	{ disk_perc, 	 "^b#656569^^c#ffffff^ SSD %2s%% ", "/"			 	     },
    { run_command,   "^b#707073^^c#ffffff^ Vol %2s%% ", "pamixer --get-volume"         },
  	{ battery_perc,  "^b#7b7b7e^^c#ffffff^ Bat %2s%% ",  "BAT0" 			 },
	{ datetime,      "^b#868689^^c#ffffff^ %s ",         "%a %e %b %k:%M"    },
};
