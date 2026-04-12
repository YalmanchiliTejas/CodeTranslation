import sys
sys.setrecursionlimit(5 * 10**5)
input = sys.stdin.readline

N = int(input())

print(800 * N - 200 * (N // 15))
