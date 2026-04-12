import sys

card = list(map(str, input().split()))

num = "" 
for i in range(len(card)):
    num += card[i]

print("YES") if int(num)%4 == 0 else print("NO")