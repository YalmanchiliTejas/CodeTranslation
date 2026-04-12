str=[input()for _ in[0]*int(input())]
print(''.join(l*min(s.count(l)for s in str)for l in sorted(set(str[0]))))