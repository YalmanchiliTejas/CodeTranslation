n = int(input(''))
adl = input('')

a = list(map(int,adl.split(' ')))

number = 0

mod = 1000000007

amari = 0

all_a = 0

for i in range(n):
    all_a = all_a + a[i]

for i in range(n):
    all_a = all_a - a[i]
    number = number + (a[i] * all_a)
    number = number % mod
amari = number % mod
print(amari)
