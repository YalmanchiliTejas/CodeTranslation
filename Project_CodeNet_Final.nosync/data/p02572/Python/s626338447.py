N = int(input())
A_list = [int(_) for _ in input().split()]

c = 10**9+7


def egcd(a, b):
    if a == 0:
        return b, 0, 1
    else:
        g, y, x = egcd(b % a, a)
        return g, x - (b // a) * y, y


def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m


inv = modinv(2, c)

sum_of_a = sum(A_list) % c
sum_of_sq_a = sum([i**2 for i in A_list]) % c

ans = (sum_of_a**2 % c - sum_of_sq_a)*inv %c

print(ans)