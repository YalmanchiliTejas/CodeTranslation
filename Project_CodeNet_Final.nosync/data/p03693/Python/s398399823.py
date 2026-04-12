if __name__=="__main__":
    rgb = raw_input().split()
    num = int("".join(rgb))
    if num%4==0:
        print "YES"
    else:
        print "NO"