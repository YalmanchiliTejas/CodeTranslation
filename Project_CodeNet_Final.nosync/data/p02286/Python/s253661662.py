class Treap:
    class TreapNode:
        def __init__(self, key, priority, leftchild=None, rightchild=None):
            self.key = key
            self.priority = priority
            self.leftchild = leftchild
            self.rightchild = rightchild

        def __repr__(self):
            return f'({self.key}, {self.priority})'

    def __init__(self):
        self.root = None
        self.inorder = []
        self.preorder = []

    def rotateR(self, t):
        s = t.leftchild
        t.leftchild = s.rightchild
        s.rightchild = t
        return s

    def rotateL(self, t):
        s = t.rightchild
        t.rightchild = s.leftchild
        s.leftchild = t
        return s

    def _insert(self, t, key, priority):
        if t is None:
            return self.TreapNode(key, priority)
        if key == t.key:
            return t
        if key < t.key:
            t.leftchild = self._insert(t.leftchild, key, priority)
            if t.priority < t.leftchild.priority:
                t = self.rotateR(t)
        else:
            t.rightchild = self._insert(t.rightchild, key, priority)
            if t.priority < t.rightchild.priority:
                t = self.rotateL(t)
        return t

    def insert(self, key, priority):
        self.root = self._insert(self.root, key, priority)

    def _delete_rotate(self, t, key):
        if t.leftchild is None and t.rightchild is None:
            return None
        elif t.leftchild is None:
            t = self.rotateL(t)
        elif t.rightchild is None:
            t = self.rotateR(t)
        else:
            if t.leftchild.priority > t.rightchild.priority:
                t = self.rotateR(t)
            else:
                t = self.rotateL(t)
        return self._delete(t, key)

    def _delete(self, t, key):
        if t is None:
            return None
        if key < t.key:
            t.leftchild = self._delete(t.leftchild, key)
        elif key > t.key:
            t.rightchild = self._delete(t.rightchild, key)
        else:
            return self._delete_rotate(t, key)
        return t

    def delete(self, key):
        self.root = self._delete(self.root, key)

    def _find(self, t, key):
        if t is None:
            return False
        elif key < t.key:
            return self._find(t.leftchild, key)
        elif key > t.key:
            return self._find(t.rightchild, key)
        else:
            return True

    def find(self, key):
        return self._find(self.root, key)

    def _walk(self, t):
        if t is None:
            return
        self.preorder.append(t.key)
        self._walk(t.leftchild)
        self.inorder.append(t.key)
        self._walk(t.rightchild)

    def walk(self):
        self.inorder.clear()
        self.preorder.clear()
        self._walk(self.root)

    def print(self):
        self.walk()
        print(' ' + ' '.join(map(str, self.inorder)))
        print(' ' + ' '.join(map(str, self.preorder)))


T = Treap()
N = int(input())
for _ in range(N):
    s = input().split()
    s[1:] = map(int, s[1:])
    if s[0] == 'insert':
        T.insert(s[1], s[2])
    if s[0] == 'find':
        print('yes' if T.find(s[1]) else 'no')
    if s[0] == 'delete':
        T.delete(s[1])
    if s[0] == 'print':
        T.print()

