n = input()
h_li = list(map(int,input().split()))

result = 1
max_hi = h_li[0]
for i in h_li[1:]:
    if max_hi <= i:
        result = result + 1
        max_hi = i

print(result)