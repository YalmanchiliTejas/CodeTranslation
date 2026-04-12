import collections
n = int(input())
l = list(input())
l = collections.Counter(list(l))
for i in range (n-1):
    l_temp = list(input())
    l_temp = collections.Counter(list(l_temp))
    l = l & l_temp
alphabet = [chr(ord('a') + i) for i in range(26)]
ans = []
for i in range (len(alphabet)):
    if l[alphabet[i]]>0:
        ans.extend([alphabet[i]]*l[alphabet[i]])
print(''.join(ans))