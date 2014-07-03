#ifndef CLUSTSTCVIEW_H
#define CLUSTSTCVIEW_H


#include "../disp3D_global.h"

#include "qglview.h"
#include <QGeometryData>
#include <QGLColorMaterial>
#include <QSharedPointer>
#include <QList>
#include <QVector>
#include <QMap>


class ClustStcModel;


class DISP3DSHARED_EXPORT ClustStcView : public QGLView
{
    Q_OBJECT
public:
    typedef QSharedPointer<ClustStcView> SPtr;            /**< Shared pointer type for ClustStcView class. */
    typedef QSharedPointer<const ClustStcView> ConstSPtr; /**< Const shared pointer type for ClustStcView class. */

    ClustStcView(bool showRegions = true, bool isStereo = true, QGLView::StereoType stereo = QGLView::RedCyanAnaglyph, QWindow *parent = 0);

    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles = QVector<int> ());

    void setModel(ClustStcModel* model);

protected:
    //=========================================================================================================
    /**
    * Initializes the current GL context represented by painter.
    *
    * @param[in] painter    GL painter which should be initialized
    */
    void initializeGL(QGLPainter *painter);

    //=========================================================================================================
    /**
    * Paints the scene onto painter. The color and depth buffers will have already been cleared, and the camera() position set.
    *
    * @param[in] painter    GL painter which is updated
    */
    void paintGL(QGLPainter *painter);

    //=========================================================================================================
    /**
    * Processes the key press event e.
    *
    * @param[in] e      the key press event.
    */
    void keyPressEvent(QKeyEvent *e);

    //=========================================================================================================
    /**
    * Processes the mouse move event e.
    *
    * @param[in] e      the mouse move event.
    */
    void mouseMoveEvent(QMouseEvent *e);

    //=========================================================================================================
    /**
    * Processes the mouse press event e.
    *
    * @param[in] e      the mouse press event.
    */
    void mousePressEvent(QMouseEvent *e);



private:
    ClustStcModel* m_pModel;

    bool m_bIsInitialized;

    bool m_bShowRegions;

    bool m_bStereo;
    QGLView::StereoType m_stereoType;

    float m_fOffsetZ;                               /**< Z offset for pop-out effect. */
    float m_fOffsetZEye;                            /**< Z offset eye. */
    QGLSceneNode *m_pSceneNodeBrain;                /**< Scene node of the hemisphere models. */
    QGLSceneNode *m_pSceneNode;                     /**< Node of the scene. */

    QGLLightModel *m_pLightModel;                   /**< The selected light model. */
    QGLLightParameters *m_pLightParametersScene;    /**< The selected light parameters. */

    bool m_bColorize;

    QGLColorMaterial material;

    QMap<qint32, qint32> m_qMapLabelIdIndex;

};

#endif // CLUSTSTCVIEW_H
