#!/usr/bin/python3
# -*- coding:utf-8 -*-

def main():
  s = list(input().strip())
  if len(set(s)) > 1:
    print('Yes')
  else:
    print('No')
  

if __name__=='__main__':
  main()

