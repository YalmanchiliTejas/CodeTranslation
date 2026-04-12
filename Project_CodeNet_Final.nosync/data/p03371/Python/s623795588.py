a, b, c, x, y = map(int, input().split())
yasui = a*x +b*y
for i in range(2*10**5):
    cost = 2*c*i + max(x-i, 0)*a + max(y-i,0)*b
    if cost<yasui:
        yasui = cost
print(yasui)