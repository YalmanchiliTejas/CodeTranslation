a = int(input())
n = [int(num) for num in input().split()]

count = 1
cp_num = n[0]
for num in n[1:] :
    if (num >= cp_num) :
        count += 1
        cp_num = num

print(count)