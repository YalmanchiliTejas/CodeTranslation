N = int(input())
S = list(map(str,input()))
K = int(input())
text = S[K-1]

correct_list = []
for i in S:
   if i != text:
       correct_list.append("*")
   else:
       correct_list.append(i)
print(''.join(correct_list))