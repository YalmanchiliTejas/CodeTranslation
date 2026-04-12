from sys import stdin
def sqmatrix(n):
  return [[0] * n for i in range(n)]

def magicsq(m):
    n = len(m)
    j = int(n/2)
    i = j + 1
    for num in range(1, n**2 + 1):
        m[i][j] = num
        i += 1
        j += 1
        i = i%n
        j = j % n
        if m[i][j] != 0:
            i += 1
            j -= 1
        if j < 0:
            j = n -1
        i = i % n
    return m

for line in stdin:
    n = int(line)
    if n == 0:
        break
    sm = sqmatrix(n)
    for row in magicsq(sm): print (''.join(map(lambda x: str(x).rjust(4, ' '),row)))