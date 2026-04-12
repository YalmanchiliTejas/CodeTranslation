#!/usr/bin/env python
# coding: utf-8


def main():
    vowel = list('aeiou')
    c = raw_input()
    if c in vowel:
        print 'vowel'
    else:
        print 'consonant'

if __name__ == '__main__':
    main()
