import sys
print('Yes' if len(set(sys.stdin.read().strip())) >= 2 else 'No')