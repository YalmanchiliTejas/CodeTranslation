N = int(input())
H = [int(elm) for elm in input().split(" ")] 

max_ = 0
count = 0
for i in range(N):
    if max_ <= H[i]:
        max_ = H[i]
        count += 1
print(count)