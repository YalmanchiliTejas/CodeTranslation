n = int(input())
a = [int(i) for i in input().split()]

a_odd = a[0::2]
a_even = a[1::2]

if n % 2 == 0:
    a_even.reverse()
    b = a_even + a_odd 
else:
    a_odd.reverse()
    b = a_odd + a_even

print(*b)
