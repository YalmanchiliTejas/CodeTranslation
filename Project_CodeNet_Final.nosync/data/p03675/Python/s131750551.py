n = int(input())
*a, = map(int, input().split())

b = list(reversed(a[1::2]))+a[0::2]
print(" ".join(map(str, b if n%2 == 0 else reversed(b))))
