# thm-binex
Solution for the [binex](https://tryhackme.com/room/binex) room from tryhackme that includes in-memory module loading in the exploit.

## Exploit
This exploit will write 'loader' shellcode to rwx memory which will map the
`stage2` shared object without it touching disk. Since the `run` function has the
`constructor` attribute, it will be executed upon successful load.  

This is a just a rough proof-of-concept to show how malware can be
loaded from an exploit without any artifacts touching disk.
