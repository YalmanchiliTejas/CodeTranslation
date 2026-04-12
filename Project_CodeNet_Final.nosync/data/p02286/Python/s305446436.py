class Node:
    def __init__(self, key, priority):
        self.key = key
        self.pri = priority
        self.parent = None
        self.left = None
        self.right = None
        
    def insert(self, z):
        if z.key < self.key:
            if self.left:
                self.left.insert(z)
            else:
                self.left = z
                z.parent = self
            if self.pri < self.left.pri:
                self.rightR()
        elif self.key < z.key:
            if self.right:
                self.right.insert(z)
            else:
                self.right = z
                z.parent = self
            if self.pri < self.right.pri:
                self.leftR()
    
    def find(self, key):
        if self.key == key:
            return True
        elif not self.left and not self.right:
            return False
        else:
            if key < self.key:
                return self.left.find(key)
            else:
                return self.right.find(key)
            
    def delete(self, key):
        if key < self.key:
            self.left.delete(key)
        elif key > self.key:
            self.right.delete(key)
        else:
            self._delete()
    
    def _delete(self):
        if not self.left and not self.right:
            if self.parent.left == self:
                self.parent.left = None
            else:
                self.parent.right = None
            del self
            return None
        elif self.left and self.right:
            if self.left.pri > self.right.pri:
                self.rightR()
            else:
                self.leftR()
        elif self.right:
            self.leftR()
        else:
            self.rightR()
        self._delete()
        
    def rightR(self):
        tmp = self.left
        if self.parent:
            if self.key < self.parent.key:
                self.parent.left = tmp
            else:
                self.parent.right = tmp
        self.left = tmp.right
        if self.left:
            self.left.parent = self
        tmp.right = self
        tmp.parent = self.parent
        self.parent = tmp
        
    def leftR(self):
        tmp = self.right
        if self.parent:
            if self.key < self.parent.key:
                self.parent.left = tmp
            else:
                self.parent.right = tmp
        self.right = tmp.left
        if self.right:
            self.right.parent = self
        tmp.left = self
        tmp.parent = self.parent
        self.parent = tmp
    
    def preo(self):
        tmp = ""
        tmp += " " + str(self.key)
        if self.left:
            tmp += self.left.preo()
        if self.right:
            tmp += self.right.preo()
        return tmp
    
    def ino(self):
        tmp = ""
        if self.left:
            tmp += self.left.ino()
        tmp += " " + str(self.key)
        if self.right:
            tmp += self.right.ino()
        return tmp

m = int(input())
root = None
for i in range(m):
    com = input().split()
    if com[0] == "insert":
        node = Node(int(com[1]), int(com[2]))
        try:
            root.insert(node)
        except AttributeError :
            root = node
    elif com[0] == "find":
        try:
            if root.find(int(com[1])):
                print("yes")
            else:
                print("no")
        except AttributeError:
            print("no")
    elif com[0] == "delete":
        try:
            root.delete(int(com[1]))
        except AttributeError:
            pass
    else:
        try:
            print(root.ino())
            print(root.preo())
        except AttributeError:
            print("None")
    c = 0
    while(True):
        if root.parent:
            root = root.parent
        else:
            break
