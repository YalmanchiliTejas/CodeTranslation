s = raw_input()
a = int(raw_input())
print "IMLU"[int(eval(s) == a)+int(eval("("*s.count("*")+s.replace("*",")*")) == a)*2]