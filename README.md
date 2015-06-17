Hello word-like MAC generator.

# Compile
```
make
```

# Install
```
make install
```


# Usage examples

## CLI
```
./mac-generator <options>
Options:
 -h              print help and exit
 -n              add line break
 -s [SEPARATOR]  specify separator (':' by default)

```

## udevd
```
cat /etc/udev/rules.d/75-macspoof.rules
ACTION=="add", ATTR{address}=="20:9b:f8:0e:fd:2f", RUN+="/sbin/set-random-mac wlan0"
```

Where `20:9b:f8:0e:fd:2f` is actual MAC of your network adapter.
