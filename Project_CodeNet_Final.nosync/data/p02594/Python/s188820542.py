#関数リスト
import sys
input = sys.stdin.readline

def I(): return int(input())

num = I()
if num >= 30:
    print("Yes")
else:
    print("No")