while True:
    try:
        x = raw_input()
        l = x.split()
        a = int(l[0])
        b = int(l[1])
        if a < b:
            print "a < b"
        elif a > b:
            print "a > b"
        else:
            print "a == b"
        
    except EOFError:
        break