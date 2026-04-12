n = int(input())
aa = list(map(int, input().split()))
if n == 1:
    print(aa[0])
elif n % 2:
    print(*(aa[-1::-2] + aa[1::2]))
else:
    print(*(aa[-1::-2] + aa[0::2]))
