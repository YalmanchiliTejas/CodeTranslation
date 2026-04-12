n = int(input())
a = [int(e) for e in input().split()]

my_sum = [0]
#print(my_sum)

tmp = 0
c = 0
for i in a:
    my_sum.append(my_sum[c]+i)
    c += 1

#print(my_sum)

my_sum2 = 0
length = len(my_sum)

c = 0
for i in a:
    my_sum2 += i * (my_sum[length-1] - my_sum[c+1])
    c += 1

print(my_sum2 % (10**9 + 7))
