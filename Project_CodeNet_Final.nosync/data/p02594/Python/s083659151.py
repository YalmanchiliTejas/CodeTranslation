#!/usr/bin/env python3

import sys

input = iter(sys.stdin.read().splitlines()).__next__

T = int(input())

print('Yes' if T >= 30 else 'No')

