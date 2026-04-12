N = input()

H = list(map(int,input().split()))

max = 0
count = 0
for i in H:
    if max <= int(i):
        max = int(i)
        count = count + 1

print(count)