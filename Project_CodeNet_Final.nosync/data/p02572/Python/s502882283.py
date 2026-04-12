n = int(input())
a = [int(s) for s in input().split()]
b = []
val = 0
sum_val= 0
for i in range(0, n):
    b.append(a[i] * sum_val) 
    sum_val+= a[i] 
val = sum(b)
print(val % (10 ** 9 + 7))