# 広義最長部分増加数列の長さを求めるdef
# 配列LIS自体は広義最長部分増加文字列ではない
import bisect
def lis(seq):
    LIS = [seq[0]]
    for i in range(1, len(seq)):
        if seq[i] >= LIS[-1]:
            LIS.append(seq[i])
        else:
            LIS[bisect.bisect_right(LIS, seq[i])] = seq[i]
    return(len(LIS))

n = int(input())
a = [0] * n
for i in range(n):
    a[i] = int(input())

b = a[::-1]
print(lis(b))