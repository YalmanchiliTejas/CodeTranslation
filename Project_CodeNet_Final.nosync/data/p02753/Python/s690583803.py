#!/usr/bin/env python

from sys import stdin, stderr

def main():
   S = stdin.readline().strip()
   print('No' if S == 'AAA' or S == 'BBB' else 'Yes')

   return 0

if __name__ == '__main__': main()
