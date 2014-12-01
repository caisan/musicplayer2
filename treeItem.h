#pragma once

#include <QList>
#include <QVariant>
#include <QHash>

class TreeItem {
    public:
        enum ITEM_TYPE {ROOT, ARTIST, SONG};
        TreeItem(const QHash<QString, QString> &data, ITEM_TYPE type, TreeItem *parent = 0);
        ~TreeItem();

        TreeItem *child(int number);
        int childCount() const;
        int columnCount() const;
        QVariant data() const;
        bool addChild(ITEM_TYPE type, QHash<QString, QString> data);
        bool removeChild(int position);
        TreeItem *parent();
        bool removeChildren(int position, int count);
        int childNumber() const;
        ITEM_TYPE getItemType() const;
        QHash<QString, QString> getItemData() const;
        QHash<QString, QString>& getItemData();


    private:
        void itemTypeAssert(ITEM_TYPE type, QHash<QString, QString> &data) const;

        ITEM_TYPE itemType;
        QList<TreeItem*> childItems;
        QHash<QString, QString> itemData;
        TreeItem *parentItem;
};