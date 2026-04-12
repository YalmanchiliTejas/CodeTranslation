#!/usr/bin/env python
# -*- coding:utf-8 -*-

c = raw_input()

if "aeiou".find(c) != -1:
  print "vowel"
else:
  print "consonant"