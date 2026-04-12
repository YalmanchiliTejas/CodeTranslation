n = int(input())
a = []
for i in range(n):
    x = int(input())
    a.append(x)
data1 = []
data2 = []
a = sorted(a)
for i in range(n // 2):
    data1.append(a[n - i - 1])
    data2.append(a[i])
    if len(data1) + 1 != n:
        data1.append(a[i])
        data2.append(a[n - i - 1])
index = n // 2
if n % 2 == 0:
    index -= 1

def set_p(data):
    if abs(data1[0] - a[index]) > abs(data1[-1] - a[index]):
        p = 0
    else:
        p = n
    return p
p1 = set_p(data1)
p2 = set_p(data2)
data1.insert(p1, a[index]) 
data2.insert(p2, a[index])
ans = 0
def calc_ans(data):
    ans = 0
    for i in range(1, n):
        ans += abs(data[i] - data[i - 1])
    return ans
    
print(max(calc_ans(data1), calc_ans(data2)))