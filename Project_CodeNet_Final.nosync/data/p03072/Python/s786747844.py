num = int(input())
ms = list(map(int, input().split()))
m_max = 0
total = 0
for i in ms:
    if i >= m_max:
        total += 1
        m_max = i
print(total)