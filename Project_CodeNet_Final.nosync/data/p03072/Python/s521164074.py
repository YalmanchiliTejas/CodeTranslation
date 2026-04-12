n = int(input())
see = 0
li = list(map(int, input().split()))
M = li[0]

for i in li:
    if M <= i:
        see += 1
        M = i

print(see)
