a,b = map(int, raw_input().split())
print 'a %s b' %(['<','==','>'][cmp(a,b)+1])