#!/usr/bin/env python3
import sys
input = sys.stdin.readline

s = input().rstrip()
if "A" in s and "B" in s:
    print("Yes")
else:
    print("No")