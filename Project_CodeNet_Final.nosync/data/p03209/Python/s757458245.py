n, x = [int(i) for i in input().split()]

a = [1]
p = [1]

for i in range(n):
    a.append(a[i]*2+3) 
    p.append(p[i]*2+1)

def patty_count(num, x_bot):
    if num == 0:
        return 0 if x_bot<=0 else 1
    elif x_bot<=1+a[num-1]:
        return patty_count(num-1, x_bot-1)
    else:
        return p[num-1] + 1 + patty_count(num-1, x_bot-2-a[num-1])
 
print(patty_count(n, x))
# print()