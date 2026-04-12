#--import&define---------------------
import math
import sys
input = sys.stdin.readline
def yes():
    print("Yes")
def no():
    print("No")

#--以下解答---------------------------------
n = int(input())
H = list(map(int, input().split()))
ans = 1
flag = True

for i in range(1,n):
    flag = True
    for j in range(0,i):
        if H[i] < H[j]:
            flag = False
            break
    if flag == True:
        ans += 1
print(ans)