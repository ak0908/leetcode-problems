class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        def leafValueSequence(root, l):
            if root.left is None and root.right is None:
                l.append(root.val)
                return
            if root.left is not None:    
                leafValueSequence(root.left, l)
            if root.right is not None:
                leafValueSequence(root.right, l)
            
        
        l1 = []
        l2 = []
        
        leafValueSequence(root1, l1)
        leafValueSequence(root2, l2)
        
        
        return l1 == l2
