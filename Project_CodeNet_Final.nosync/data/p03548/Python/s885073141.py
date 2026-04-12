##
## python3
##

N = input()
X, Y, Z = N.split()

Xh = int(X, 10)
Yh = int(Y, 10)
Zh = int(Z, 10)

sum = 0

for i in range(1, Xh):
    if (Yh+Zh)*i+Zh <= Xh:
        sum += 1
    else:
        break

print(sum)