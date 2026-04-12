n = int(input())
a = list(input().split())
if n == 1:
    print(a[0])
elif n % 2:
    print(*(a[-1::-2] + a[1::2]))
else:
    print(*(a[-1::-2] + a[0::2]))
