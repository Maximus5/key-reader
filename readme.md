# RAW key reader

This tiny tool reads unprocessed input from stdin.

Just compile it on Unix or using cygwin and run result binary.


## How to compile

First, be sure you have `g++` installed (simple `gcc` is not enough).

> apt-get g++

Than, you may build key-reader

> g++ key-reader.cpp -o kr

Set permission for the binary file

> chmod 777 ./kr

And now you may run it

> ./kr


## Alternatives

On **Unix** you may run `showkey -a`.

On **Windows** there is `KeyEvents.exe` from ConEmu project:
<https://conemu.github.io/en/KeyEvents.html>.
