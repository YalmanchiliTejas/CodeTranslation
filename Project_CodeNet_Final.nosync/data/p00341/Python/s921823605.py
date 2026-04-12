data = list(map(int, input().split()))

data.sort()

ans = "yes"
for i in range(0, 12, 4) :
    if data[i] != data[i+1] or data[i] != data[i+2] or data[i] != data[i+3] :
        ans = "no"

print(ans)
