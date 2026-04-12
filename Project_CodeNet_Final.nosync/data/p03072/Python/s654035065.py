N = int(input())
Hn = list(map(int,input().split(' ')))
current_max = 0
amount_count = 0
for val in Hn:
    if current_max <= val:
        current_max = val
        amount_count += 1
print(amount_count)
