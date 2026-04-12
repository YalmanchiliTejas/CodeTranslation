#!/bin/bash
''':'
docker run --rm -it -v $(cd $(dirname $0) && pwd):/vo:ro pypy:3-2.4.0 \
   /bin/bash -c "pypy3 /vo/$(basename $0) < /vo/g.inp"
exit $?
'''
import sys

def _s(): return sys.stdin.readline().strip()

def main():
    a = set(c for c in _s())
    if len(a)==1: print("No")
    else: print("Yes")

if __name__ == "__main__":
    main()
