n = input()
 
max = 10**9 + 7
 
a_list = [int(a) % max for a in input().split(" ")]
a_sum = sum(a_list)

total = 0
for i in range(0, len(a_list)-1):
    a_sum -= a_list[i]
    total += a_list[i] * a_sum
total = total % max
print(total)
