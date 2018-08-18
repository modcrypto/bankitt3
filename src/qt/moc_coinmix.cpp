/****************************************************************************
** Meta object code from reading C++ file 'coinmix.h'
**
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt/coinmix.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'coinmix.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Coinmix_t {
    QByteArrayData data[17];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Coinmix_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Coinmix_t qt_meta_stringdata_Coinmix = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Coinmix"
QT_MOC_LITERAL(1, 8, 18), // "transactionClicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "index"
QT_MOC_LITERAL(4, 34, 14), // "DarKsendStatus"
QT_MOC_LITERAL(5, 49, 10), // "setBalance"
QT_MOC_LITERAL(6, 60, 7), // "CAmount"
QT_MOC_LITERAL(7, 68, 7), // "balance"
QT_MOC_LITERAL(8, 76, 18), // "unconfirmedBalance"
QT_MOC_LITERAL(9, 95, 15), // "immatureBalance"
QT_MOC_LITERAL(10, 111, 17), // "anonymizedBalance"
QT_MOC_LITERAL(11, 129, 16), // "watchOnlyBalance"
QT_MOC_LITERAL(12, 146, 18), // "watchUnconfBalance"
QT_MOC_LITERAL(13, 165, 20), // "watchImmatureBalance"
QT_MOC_LITERAL(14, 186, 14), // "toggleDarksend"
QT_MOC_LITERAL(15, 201, 12), // "DarksendAuto"
QT_MOC_LITERAL(16, 214, 13) // "DarksendReset"

    },
    "Coinmix\0transactionClicked\0\0index\0"
    "DarKsendStatus\0setBalance\0CAmount\0"
    "balance\0unconfirmedBalance\0immatureBalance\0"
    "anonymizedBalance\0watchOnlyBalance\0"
    "watchUnconfBalance\0watchImmatureBalance\0"
    "toggleDarksend\0DarksendAuto\0DarksendReset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Coinmix[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   47,    2, 0x0a /* Public */,
       5,    7,   48,    2, 0x0a /* Public */,
      14,    0,   63,    2, 0x08 /* Private */,
      15,    0,   64,    2, 0x08 /* Private */,
      16,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6, 0x80000000 | 6,    7,    8,    9,   10,   11,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Coinmix::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Coinmix *_t = static_cast<Coinmix *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->transactionClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->DarKsendStatus(); break;
        case 2: _t->setBalance((*reinterpret_cast< const CAmount(*)>(_a[1])),(*reinterpret_cast< const CAmount(*)>(_a[2])),(*reinterpret_cast< const CAmount(*)>(_a[3])),(*reinterpret_cast< const CAmount(*)>(_a[4])),(*reinterpret_cast< const CAmount(*)>(_a[5])),(*reinterpret_cast< const CAmount(*)>(_a[6])),(*reinterpret_cast< const CAmount(*)>(_a[7]))); break;
        case 3: _t->toggleDarksend(); break;
        case 4: _t->DarksendAuto(); break;
        case 5: _t->DarksendReset(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Coinmix::*_t)(const QModelIndex & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Coinmix::transactionClicked)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Coinmix::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Coinmix.data,
      qt_meta_data_Coinmix,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Coinmix::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Coinmix::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Coinmix.stringdata0))
        return static_cast<void*>(const_cast< Coinmix*>(this));
    return QWidget::qt_metacast(_clname);
}

int Coinmix::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Coinmix::transactionClicked(const QModelIndex & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
