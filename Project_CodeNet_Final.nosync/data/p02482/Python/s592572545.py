n = map(int, raw_input().split())
print "a " + ("<" if n[0] < n[1] else ">" if n[0] > n[1] else "==") + " b"