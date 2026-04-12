from sys import stdin
import bisect

n = int(stdin.readline().rstrip())

print(n*800-200*(n//15))