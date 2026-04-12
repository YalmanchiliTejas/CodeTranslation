# input
N = int(input())

a = N // 15
b = N % 15

ans = (800 * 15 - 200) * a + 800 * b
print(ans)